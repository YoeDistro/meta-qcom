DESCRIPTION = "Tiny ramdisk image with glymur CRD firmware files"

PACKAGE_INSTALL += " \
    packagegroup-glymur-crd-firmware \
"

require initramfs-firmware-image.inc
