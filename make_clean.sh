#
#   Script to clean all previously built resources. 
#   Clobbers output kernel and driver modules, targets tegra21_defconfig
#   afterwards for next build.
#

#!/bin/bash
if [ -z "$TEGRA_KERNEL_OUT" ]
then

echo "TEGRA_KERNEL_OUT is not set, source the setup_crosdev.sh"

else
echo "cleaning"

make O=$TEGRA_KERNEL_OUT clean
rm -r $TEGRA_KERNEL_OUT/*
rm -r $L4T_ROOT_DIR/built_modules/*
rm $L4T_ROOT_DIR/Linux_for_Tegra/kernel/dtb/*
#rm -r $TEGRA_KERNEL_OUT/.config
make mrproper
make O=$TEGRA_KERNEL_OUT mrproper
#make O=$TEGRA_KERNEL_OUT tegra_t186ref_gnu_linux_defconfig 
make O=$TEGRA_KERNEL_OUT tegra21_cti_defconfig 

fi
