#!/bin/bash
case "$(cat /proc/device-tree/compatible)" in
	*rk3588*)
		{
			echo "type=dec"
			echo "codecs=VP8:VP9:H.264:H.265:AV1"
			echo "max-width=7680"
			echo "max-height=4320"
		} > /dev/video-dec0
		;;
	*rk3568*)
		{
			echo "type=dec"
			echo "codecs=VP8:VP9:H.264:H.265"
			echo "max-width=3840"
			echo "max-height=2160"
		} > /dev/video-dec0
		;;
	*)
		echo dec > /dev/video-dec0
esac
chown root:video /dev/video-dec0
chmod 0660 /dev/video-dec0
echo enc > /dev/video-enc0
chown root:video /dev/video-enc0
chmod 0660 /dev/video-enc0
