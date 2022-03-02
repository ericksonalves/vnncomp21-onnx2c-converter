#include <algorithm>
#include <chrono>
#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> list_all_files_with_extension(const std::string &path, const std::string &extension)
{
    std::vector<std::string> filenames;

    for (std::experimental::filesystem::recursive_directory_iterator it(path), end; it != end; ++it)
    {
        const std::experimental::filesystem::path path = it->path();

        if (!std::experimental::filesystem::is_directory(path) && path.extension() == extension)
        {
            std::stringstream stream;

            stream << path.parent_path().string() << std::experimental::filesystem::path::preferred_separator
                   << path.filename().string();

            filenames.push_back(stream.str());
        }
    }

    std::sort(filenames.begin(), filenames.end());

    return filenames;
}

std::string run_process(const std::string &cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);

    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }

    return result;
}

std::string process_output_filename(const std::string &input_filename, const std::string &input_path,
                                    const std::string &output_path, const std::string &input_extension,
                                    const std::string &output_extension)
{
    const std::string path = std::experimental::filesystem::path(input_filename).string();

    std::string output_filename = std::regex_replace(path, std::regex(input_path), output_path);
    output_filename = std::regex_replace(output_filename, std::regex("\\" + input_extension), output_extension);

    std::experimental::filesystem::path p(output_filename);

    if (!std::experimental::filesystem::exists(p.parent_path()))
    {
        std::experimental::filesystem::create_directories(p.parent_path());
    }

    return output_filename;
}

void run_converter_and_save_output(const std::string &converter_path, const std::string &input_filename,
                                   const std::string &output_filename)
{
    const std::string output = run_process(converter_path + " " + input_filename);

    std::ofstream output_file(output_filename);

    output_file << output << std::endl;

    output_file.close();
}

int main(int argc, const char *argv[])
{
    if (argc != 6)
    {
        std::cout << "Wrong usage! Expected input is: <input_extension> <output_extension> <input_path> "
                  << "<output_path> <converter_bin_path>" << std::endl;
        return -1;
    }

    const std::string input_extension(argv[1]);
    const std::string output_extension(argv[2]);
    const std::string input_path(argv[3]);
    const std::string output_path(argv[4]);
    const std::string converter_path(argv[5]);

    std::cout << "Input Extension: " << input_extension << std::endl;
    std::cout << "Output Extension: " << output_extension << std::endl;
    std::cout << "Input Path: " << input_path << std::endl;
    std::cout << "Output Path: " << output_path << std::endl;
    std::cout << "Converter Path: " << converter_path << std::endl;

    const std::vector<std::string> filenames = list_all_files_with_extension(input_path, input_extension);

    std::cout << "Found " << filenames.size() << " file(s) matching the desired extension." << std::endl;

    std::chrono::steady_clock::time_point overall_from = std::chrono::steady_clock::now();

    for (const std::string &filename : filenames)
    {
        std::chrono::steady_clock::time_point from = std::chrono::steady_clock::now();

        std::cout << "Running converter with input file: " << filename << std::endl;

        const std::string output_filename = process_output_filename(filename, input_path, output_path,
                                                                    input_extension, output_extension);

        std::cout << "Output filename: " << output_filename << std::endl;

        run_converter_and_save_output(converter_path, filename, output_filename);

        std::chrono::steady_clock::time_point to = std::chrono::steady_clock::now();

        long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(to - from).count();

        std::cout << "Finished in " << elapsed << "[ms]" << std::endl;
    }

    std::chrono::steady_clock::time_point overall_to = std::chrono::steady_clock::now();

    long overall_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                               overall_to - overall_from)
                               .count();

    std::cout << "Finished all conversions in " << overall_elapsed << "[ms]" << std::endl;

    return 0;
}
