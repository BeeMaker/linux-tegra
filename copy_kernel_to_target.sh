#!/bin/bash

scp /usr/mg/28.1_TX1/tegra_kernel_out/arch/arm64/boot/zImage /usr/mg/28.1_TX1/tegra_kernel_out/arch/arm64/boot/Image root@192.168.128.35:/boot/ 
#scp /disk2/mg/linux4tegra/tegra_kernel_out/arch/arm64/boot/dts/tegra210-tx1-cti-ASG006-IMX274-3CAM.dtb root@192.168.128.37:/boot/ 
#scp /disk2/mg/linux4tegra/tegra_kernel_out/arch/arm64/boot/dts/tegra210-jetson-tx1-p2597-2180-a01-devkit.dtb root@192.168.128.37:/boot/ 
#scp /usr/mg/24.2_stock/tegra_kernel_out/drivers/tty/serial/8250/8250_pci.ko root@206.130.75.228:/root/ 
