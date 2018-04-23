old-dtb := $(dtb-y)
dtb-y :=
makefile-path := platform/t210/jetson/kernel-dts

dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-cv-base-p2597-2180-a00.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-cv-p2597-2180-a00.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-tx1-p2597-2180-a01-android-devkit.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-tx1-p2597-2180-a01-devkit.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-e-base-p2595-0000-a00.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-e-p2595-0000-a00-00.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-jetson-tx1-p2597-2180-a02-devkit-24x7.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG001.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG002.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG003.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG006-IMX274-3CAM.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG006-IMX185-3CAM.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-VPG003-IMX185-3CAM.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-VPG003-IMX274-3CAM.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG008-IMX274.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG008-IMX185.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG007.dtb
dtb-$(CONFIG_ARCH_TEGRA_210_SOC) += tegra210-tx1-cti-ASG005.dtb

ifneq ($(dtb-y),)
dtb-y := $(addprefix $(makefile-path)/,$(dtb-y))
endif

dtb-y += $(old-dtb)

