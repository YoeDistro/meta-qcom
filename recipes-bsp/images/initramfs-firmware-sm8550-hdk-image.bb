DESCRIPTION = "Tiny ramdisk image with SM8550 HDK devices firmware files"

PACKAGE_INSTALL += " \
    packagegroup-sm8550-hdk-firmware \
"

BAD_RECOMMENDATIONS = " \
"

require initramfs-firmware-image.inc
