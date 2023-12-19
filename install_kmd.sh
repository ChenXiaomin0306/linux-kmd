TARGET_KERNEL_VERSION=`uname -r`
set -e
if [ ! -d /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/ ]; then
	mkdir -p /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/
fi


make usedefconfig 
make -j32 
cp -f ./compat/drm_ukmd_compat.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/
cp -f ./drivers/gpu/drm/drm.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/
cp -f ./drivers/gpu/drm/drm_kms_helper.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/
cp -f ./drivers/gpu/drm/drm_shmem_helper.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/

cp -f ./drivers/gpu/drm/i915/i915.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/

cp -f ./drivers/misc/mei/mei.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/
cp -f ./drivers/misc/mei/mei-me.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/
cp -f ./drivers/misc/mei/mei-gsc.ko /lib/modules/${TARGET_KERNEL_VERSION}/extra/ukmd/

depmod -a ${TARGET_KERNEL_VERSION}

echo -e $ECHO_PREFIX_INFO "Calling mkinitrd upon ${TARGET_KERNEL_VERSION} kernel..."
dracut --force /boot/initramfs-"${TARGET_KERNEL_VERSION}".img ${TARGET_KERNEL_VERSION}
