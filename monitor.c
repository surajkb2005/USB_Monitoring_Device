#include <libudev.h>
#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "whitelist.h"

void start_monitoring() {
    struct udev *udev = udev_new();
    if (!udev) {
        printf("Cannot create udev\n");
        return;
    }

    struct udev_monitor *mon =
        udev_monitor_new_from_netlink(udev, "udev");

    udev_monitor_filter_add_match_subsystem_devtype(
        mon, "usb", NULL);

    udev_monitor_enable_receiving(mon);

    printf("Listening for USB events...\n");

    while (1) {
        struct udev_device *dev =
            udev_monitor_receive_device(mon);

        if (dev) {
            const char *action =
                udev_device_get_action(dev);

            const char *vendor =
                udev_device_get_sysattr_value(dev, "idVendor");

            const char *product =
                udev_device_get_sysattr_value(dev, "idProduct");

            if (action && vendor && product) {

                printf("Action: %s | Vendor: %s | Product: %s\n",
                       action, vendor, product);

                log_event(action, vendor, product);

                if (!is_whitelisted(vendor, product)) {
                    printf("⚠️ ALERT: Unknown USB Device!\n");
                }
            }

            udev_device_unref(dev);
        }
    }

    udev_unref(udev);
}