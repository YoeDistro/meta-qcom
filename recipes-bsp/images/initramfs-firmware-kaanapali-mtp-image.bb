DESCRIPTION = "Tiny ramdisk image with Kaanapali MTP firmware files"

PACKAGE_INSTALL += " \
    packagegroup-kaanapali-mtp-firmware \
"

require initramfs-firmware-image.inc
