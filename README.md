## Deprecation note!

**Please note: This repository is deprecated and it is no longer actively maintained**.

# Getting started with Bootloader Blinky on mbed OS

This example shows how to build and use an application with a prebuilt bootloader. For steps on how to create the bootloader, see [mbed-os-example-bootloader](https://github.com/ARMmbed/mbed-os-example-bootloader).

To read more about the bootloader, please visit [bootloader tutorial](https://docs.mbed.com/docs/mbed-os-handbook/en/latest/advanced/bootloader/).

## Required hardware
* A supported board - [u-blox EVK-ODIN-W2](https://developer.mbed.org/platforms/ublox-EVK-ODIN-W2/), [Nucleo F429ZI](https://developer.mbed.org/platforms/ST-Nucleo-F429ZI/) or [K64F](https://developer.mbed.org/platforms/FRDM-K64F/).
* CI test shield.
* SD card.

## Import the example application

From the command-line, import the example:

```
mbed import mbed-os-example-bootloader-blinky
cd mbed-os-example-bootloader-blinky
```

## Set up application to use bootloader

All supported boards mentioned above are set up to use bootloader with a CI test shield.

To either use a different board or a different SD card slot, you must rebuild the bootloader and update the application.
To do this:

1. Create a bootloader for your board in the project [mbed-os-example-bootloader](https://github.com/ARMmbed/mbed-os-example-bootloader). The bootloader image is named ``mbed-os-example-bootloader.bin``.
2. Update your board to use the newly created bootloader image. To do this, set the target (replace ``<TARGET_NAME>`` with your target name) value `bootloader_img` to the file path of the bootloader image.

```
    "target_overrides": {
        ...
        "<TARGET_NAME>": {
            "target.bootloader_img": "bootloader/<TARGET_NAME>.bin"
        },
        ...
```

## Now compile

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`). For example, for the ARM Compiler 5:

```
mbed compile -m <TARGET_NAME> -t ARM
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
Merging Regions:
  Filling region bootloader with bootloader/<TARGET_NAME>.bin
  Filling region application with .\BUILD\<TARGET_NAME>\GCC_ARM\mbed-os-example-bootloader-blinky_application.bin
Space used after regions merged: 0x296f4
+-----------------------+-------+-------+-------+
| Module                | .text | .data |  .bss |
+-----------------------+-------+-------+-------+
| Fill                  |    70 |     4 |     9 |
| Misc                  | 20952 |  2184 |   112 |
| drivers               |   118 |     4 |   100 |
| features/FEATURE_LWIP |    44 |     0 | 12536 |
| hal                   |   418 |     0 |     8 |
| platform              |  1148 |     4 |   269 |
| rtos                  |    38 |     4 |     4 |
| rtos/rtx              |  6089 |    20 |  6870 |
| targets/TARGET_STM    |  6511 |     4 |   700 |
| Subtotals             | 35388 |  2224 | 20608 |
+-----------------------+-------+-------+-------+
Allocated Heap: 24576 bytes
Allocated Stack: unknown
Total Static RAM memory (data + bss): 22832 bytes
Total RAM memory (data + bss + heap + stack): 47408 bytes
Total Flash memory (text + data + misc): 37612 bytes

Image: .\BUILD\NUCLEO_F429ZI\GCC_ARM\mbed-os-example-bootloader-blinky.bin
```

## Program bootloader and application

1. Connect your mbed device to the computer over USB.
1. Copy the mbed-os-example-bootloader-blinky binary file to the mbed device.
1. Press the reset button to start the program.

The LED on your platform turns on and off.

## Program application using SD card

1. Connect the SD card to your computer.
1. Copy the application binary (mbed-os-example-bootloader-blinky_application.bin) to the root of the SD card.
1. Remove the SD card from your PC, and plug it into the mbed board.
1. Press the reset button to start the firmware update.

If a terminal is open, the following prints:

```
Firmware update found
Starting application
```

You then see the LED on your platform turning on and off.

## Troubleshooting

1. Make sure `mbed-cli` is working correctly and its version is `>1.0.0`.

 ```
 mbed --version
 ```

 If not, you can update it:

 ```
 pip install mbed-cli --upgrade
 ```

2. If using Keil MDK, make sure you have a license installed. [MDK-Lite](http://www.keil.com/arm/mdk.asp) has a 32 KB restriction on code size.
