#include <iostream>



   using namespace std;
   //Construct a Zone Query packet
   // 4 bytes - Signature "Ohz " = 0x6f, 0x68, 0x7a, 0x20
   // 1 bytes - Version = 1
   // 1 bytes - Type (0 = Zone Query, 1 = Zone Uri)
   // 2 bytes - Entire message length = 12 + zone length
   // 4 bytes - Length in bytes of the zone ID
   // n bytes - Zone ID to query

    //This value will be passed in to the function
    const string zoneID = "714f9b83b2beb170b19db6a281d2f9512";

    //Calculate all of the values that we need
    const short packetLength = 4 + 1 + 1 + 2 + 4 + zoneID.size();
    size_t zoneIDLength = zoneID.size();
    char buffer[packetLength];
    string headerText = "Ohz ";
    string version = "1";
    string messageType = "0";

    //Build the packet
    memcpy(buffer + 0, headerText.c_str(), 4);
    memcpy(buffer + 4, version.c_str(), 1);
    memcpy(buffer + 5, messageType.c_str(), 1);
    memcpy(buffer + 6, &packetLength, sizeof(packetLength));
    memcpy(buffer + 8, &zoneIDLength, sizeof(zoneIDLength));
    memcpy(buffer + 12, zoneID.c_str(), zoneIDLength);

    LOGDEB("Buffer: " << buffer << " : Ended" << endl);
