# vnncomp21-onnx2c-converter

This repository contains a converter implementation that takes a folder, finds files matching a given extension, invokes a converter, and saves each result in the converted files. It has been used here to converter `onnx` files from the VNN-Comp '21 to `c` files using `onnx2c` tool.

## Usage

Pre-requisites:
- a working onnx2c binary (more information available at https://github.com/kraiskil/onnx2c);
- g++ with support to C++17 (gcc v5.0+)

Building:

```
git clone https://github.com/ericksonalves/vnncomp21-onnx2c-converter.git
cd vnncomp21-onnx2c-converter
chmod +x build.sh
./build.sh
```

Running:

```
./main <input_extension> <output_extension> <input_path> <output_path> <converter_bin_path>
```

For convenience, a sell script file with sample parameters is available at `run.sh`.

## VNN-COMP '21 Supported Benchmarks

|           **Name**          | **Status** |                        **Note**                        |
|:---------------------------:|:----------:|:------------------------------------------------------:|
| ACASXU_run2a_1_1_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_2_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_3_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_4_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_5_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_6_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_7_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_8_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_1_9_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_1_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_2_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_3_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_4_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_5_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_6_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_7_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_8_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_2_9_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_1_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_2_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_3_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_4_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_5_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_6_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_7_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_8_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_3_9_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_1_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_2_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_3_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_4_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_5_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_6_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_7_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_8_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_4_9_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_1_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_2_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_3_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_4_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_5_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_6_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_7_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_8_batch_2000 |   SUCCESS  |                            -                           |
| ACASXU_run2a_5_9_batch_2000 |   SUCCESS  |                            -                           |
|          resnet_2b          |   SUCCESS  |                            -                           |
|          resnet_4b          |   SUCCESS  |                            -                           |
|        cifar10_2_255        |   FAILED   | Reshaping to a run-time defined shape is not supported |
|   cifar10_2_255_simplified  |   SUCCESS  |                            -                           |
|        cifar10_8_255        |   FAILED   | Reshaping to a run-time defined shape is not supported |
|   cifar10_8_255_simplified  |   SUCCESS  |                            -                           |
|       convBigRELU__PGD      |   SUCCESS  |                            -                           |
|   ffnnSIGMOID__Point_6x200  |   SUCCESS  |                            -                           |
|       mnist_relu_9_200      |   SUCCESS  |                            -                           |
|        cifar10_large        |   SUCCESS  |                            -                           |
|        cifar10_medium       |   SUCCESS  |                            -                           |
|        cifar10_small        |   SUCCESS  |                            -                           |
|     mnist-net_256x2.onnx    |   SUCCESS  |                            -                           |
|     mnist-net_256x4.onnx    |   SUCCESS  |                            -                           |
|     mnist-net_256x6.onnx    |   SUCCESS  |                            -                           |
|        cifar_base_kw        |   SUCCESS  |                            -                           |
|        cifar_deep_kw        |   SUCCESS  |                            -                           |
|        cifar_wide_kw        |   SUCCESS  |                            -                           |
|          test_nano          |   FAILED   |         Unimplemented - multidimiensional Relu         |
|           test_sat          |   SUCCESS  |                            -                           |
|          test_small         |   SUCCESS  |                            -                           |
|          test_tiny          |   SUCCESS  |                            -                           |
|          test_unsat         |   SUCCESS  |                            -                           |
|       Convnet_avgpool       |   SUCCESS  |                            -                           |
|       Convnet_maxpool       |   SUCCESS  |                            -                           |