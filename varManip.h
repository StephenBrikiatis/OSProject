/*Authors: Stephen Brikiatis
Class:  CSI-385-01
Assignment: FAT12
Date Assigned: 08/30/16
Due Date: 11/2/16

Description: This code is the header for variables to be held outside of 
the main systems since all will need access.

Certification of Authenticity:
We certify that this assignment is entirely our own work.
*/
#ifndef VAR_MANIP_H
#define VAR_MANIP_H

#include "superVar.h"
SuperVar readSuperVars();

void writeSuperVars(SuperVar data);

void startSuperVars();
#endif