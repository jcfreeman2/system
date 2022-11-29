/*
 *  FIFOConnection.h
 *  System
 *
 *  Created by Matthias Wiesmann on 07.04.05.
 *  Copyright 2005 CERN. All rights reserved.
 *
 */

#ifndef SYSTEM_FIFO_CONNECTION
#define SYSTEM_FIFO_CONNECTION

#include "system/File.h"
#include "system/Descriptor.h"

namespace System {
    
    /** This class offers some basic tool to communicate simple messages using a file-system based FIFO
      * (named pipe). 
      * \author Matthias Wiesmann
      * \version 1.0
      */
    
    class FIFOConnection : public File {
	
    public:
	static const unsigned int MAX_MESSAGE_LEN ;
 
	FIFOConnection(const std::string &name) ; 
	FIFOConnection(const File &file) ; 

	~FIFOConnection() ;

	void make(mode_t perm=0622) const ; 

	std::string read_message() const ; 
	void send_message(const std::string &message) const ; 

	System::Descriptor* open_r(bool block = true);
	System::Descriptor* open_w(bool block = true);
	System::Descriptor* open_rw(bool block = true);
	void send(const std::string &message) const;
	std::string read() const;
	int fd() const;
	void close();

    private:
	System::Descriptor* m_fifo_fd;
	bool m_is_blocking;
	
    } ; // FIFOConnection
    
} // System

#endif
