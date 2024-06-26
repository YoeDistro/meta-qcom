DEPENDS += "cabextract-native"

S = "${UNPACKDIR}"

require recipes-bsp/firmware/firmware-qcom.inc

WOA_FW_URL = "https://github.com/WOA-Project/Qualcomm-Reference-Drivers/raw/master/${WOA_SUBDIR}/${PV}"

FILES:linux-firmware-qcom-${FW_QCOM_NAME}-adreno += "${FW_QCOM_PATH}/qcdxkmsuc*.mbn"
FILES:linux-firmware-qcom-${FW_QCOM_NAME}-audio += "${FW_QCOM_PATH}/qcadsp*.mbn"
FILES:linux-firmware-qcom-${FW_QCOM_NAME}-compute += "${FW_QCOM_PATH}/qccdsp*.mbn"
FILES:linux-firmware-qcom-${FW_QCOM_NAME}-modem += "${FW_QCOM_PATH}/qcmpss*.mbn ${FW_QCOM_PATH}/qcdsp*.mbn"
FILES:linux-firmware-qcom-${FW_QCOM_NAME}-sensors += "${FW_QCOM_PATH}/qcslpi*.mbn"
FILES:linux-firmware-qcom-${FW_QCOM_NAME}-venus += "${FW_QCOM_PATH}/qcvss*.mbn"

do_compile:append() {
    for file in ${UNPACKDIR}/*cab ; do
        cabextract $file || exit 1
    done
    if [ -r "WLANMDSP.MBN" ] ; then
        cp WLANMDSP.MBN wlanmdsp.mbn
    fi
}

do_install:append() {
    install -d ${D}${FW_QCOM_PATH}

    install -m 0644 ${B}/*.mbn ${D}${FW_QCOM_PATH}
    ls ${B}/*.elf && install -m 0644 ${B}/*.elf ${D}${FW_QCOM_PATH}

    install -m 0644 ${UNPACKDIR}/*.jsn ${D}${FW_QCOM_PATH}
}
