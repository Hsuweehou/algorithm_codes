#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
extern "C"
{
    #include <libudev.h>
}

typedef struct {
    //const char *dpath;
    std::string dpath;
    int flag;
} Dev_list;

//清空结构体
Dev_list clearMyStruct(Dev_list *devl)
{
    devl->dpath = {0};
    devl->flag = 0;
 
    return *devl;
}


int getCamIDFromPidVid(const char *pid, const char *vid, Dev_list *devs)
{
    struct udev *udev = NULL;
    struct udev_enumerate *udev_enumerate = NULL;
    struct udev_list_entry *list_entry = NULL;
    int count = 0;
    int flag = 0;
    char devName[128]={0};

    udev = udev_new();
    if(udev == NULL)
    {
        std::cout << "No udev detected!" << "\n";
        return 0;
    }
    udev_enumerate = udev_enumerate_new(udev);
    if(udev_enumerate == NULL)
    {
        std::cout << "No udev_enumerate detected!" << "\n";
        return 0;
    }

    udev_enumerate_add_match_subsystem(udev_enumerate, "video4linux");
    udev_enumerate_scan_devices(udev_enumerate);
    udev_list_entry_foreach(list_entry, udev_enumerate_get_list_entry(udev_enumerate))
    {
        struct udev_device *device;
        device = udev_device_new_from_syspath(udev_enumerate_get_udev(udev_enumerate), udev_list_entry_get_name(list_entry));
        if(device!=NULL)
        {
            std::cout << "Camera devices detected!" << "\n";

        if(udev_device_get_property_value(device, "ID_VENDOR_ID")!=NULL &&
            udev_device_get_property_value(device, "ID_MODEL_ID")!=NULL &&
            !strcmp(vid, udev_device_get_property_value(device, "ID_VENDOR_ID")) &&
            !strcmp(pid, udev_device_get_property_value(device, "ID_MODEL_ID")))
            {
                sprintf(devName,"/dev/video%s", udev_device_get_sysnum(device));
                        flag = 1;
                count++;
            }
        udev_device_unref(device);
        }
        else
        {
            std::cout << "No camera devices detected!" << "\n";
        }
    }
    if(flag!=0)
    {   //std::cout << devName << "\n";// /dev/video*
        //char *s = devName;
        if(strlen(devName)>0)
            devs->dpath = devName;
            std::cout << typeid(atoi(&(devs->dpath.back()))).name() << '\n';
            //std::cout << devs->dpath << "\n";
            //memcpy(dpath, s, strlen(devName));

    }
        udev_enumerate_unref(udev_enumerate);
        udev_unref(udev);
        devs->flag = flag;
        return flag;
}


/*
exec: g++ -o cameratest camera_device.cpp -ludev
so:   g++ camera_device.cpp -fPIC -shared -o libgetCamId.so
*/


int main(){
    const char* Avid = "0bda";
    const char* Apid = "57b8";
    Dev_list devsss;
    char test = devsss.dpath.back();//(devsss.dpath).at((devsss.dpath).length());
    int devss = getCamIDFromPidVid(Apid, Avid, &devsss);
    std::cout << typeid(atoi(&(devsss.dpath.back()))).name() << "\n";
    std::cout << typeid(devsss.flag).name()<< "\n";
    return 0;
}
