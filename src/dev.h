/***************************************************************************
                                   dev.h
                             -------------------
    begin                : Wed Aug 1 2001
    copyright            : (C) 2001 - 20007 by Roland Riegel
    email                : feedback@roland-riegel.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef DEV_H
#define DEV_H

#include <curses.h>
#include <config.h>
#include "proc.h"
#include "status.h"

class Status;
class Graph;
class Window;

#define STANDARD_HIDE_GRAPHS false
#define STANDARD_SLEEP_INTERVAL 500
#define STANDARD_TRAFFIC_FORMAT Status::kilobit
#define STANDARD_DATA_FORMAT Status::megabyte

#if defined(HAVE_LINUX)
    #define STANDARD_NETWORK_DEVICE "eth0"
#elif defined(HAVE_BSD)
    #define STANDARD_NETWORK_DEVICE "fxp0"
#elif defined(HAVE_SOLARIS)
    #define STANDARD_NETWORK_DEVICE "hme0"
#elif defined(HAVE_HPUX)
    #define STANDARD_NETWORK_DEVICE "lan0"
#endif

class Dev : public Proc
{
    public:
        Dev();
        ~Dev();

        void update();
        void print(Window&);
        void setDeviceNumber(int);
        void setTotalNumberOfDevices(int);
        
    private:
        Status::status_format trafficFormat();
        Status::status_format dataFormat();
        
        int m_devicenumber;
        int m_totalnumberofdevices;
        
        Status* device_status[2];
        Graph* traffic_graph[2];
};

#endif
