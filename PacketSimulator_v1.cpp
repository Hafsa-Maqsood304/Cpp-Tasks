#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct Packet
{
    int PacketID;
    string SourceIP;
    string DestinationIP;
    string Payload;
    int sequenceNumber;
};

int main()
{
    cout << "Packet Simulator" << endl;
    cout << "----------------" << endl;
    cout << "Enter the message:" << endl;
    string message,origin;
    getline(cin, origin);
    message = origin;

    queue<Packet> packetQueue;
    
    //For autamating the packet creation and adding to the queue
    int i=0;
    while (!message.empty()) {
        Packet packet;
        packet.PacketID = i + 1;
        packet.SourceIP = "192.168.1.1";
        packet.DestinationIP = "192.168.1.2";

        packet.Payload = message.substr(0, 4); // Assuming each packet carries 4 characters
        message.erase(0, 4); // Remove the first 4 characters from the message
        
        packet.sequenceNumber = i+1;
        
        packetQueue.push(packet);
        i++;
    }

    queue<Packet> tempQueue = packetQueue; // Create a temporary queue to display packets
    while (!tempQueue.empty()) {
        cout << "Packet ID: " << tempQueue.front().PacketID << endl;
        cout << "Source IP: " << tempQueue.front().SourceIP << endl;
        cout << "Destination IP: " << tempQueue.front().DestinationIP << endl;
        cout << "Payload: " << tempQueue.front().Payload << endl;
        cout << "Sequence Number: " << tempQueue.front().sequenceNumber << endl;
        tempQueue.pop();
    }

    // Example of Manually creating a single packet and displaying its details
    /*
    Packet packet1;
    packet1.PacketID = 1;
    packet1.SourceIP = "192.168.1.1";
    packet1.DestinationIP = "192.168.1.2";
    packet1.Payload = "Hefsa";
    packet1.sequenceNumber = 1;

    cout << "Packet ID: " << packet1.PacketID << endl;
    cout << "Source IP: " << packet1.SourceIP << endl;
    cout << "Destination IP: " << packet1.DestinationIP << endl;
    cout << "Payload: " << packet1.Payload << endl;
    cout << "Sequence Number: " << packet1.sequenceNumber << endl;
    */
}