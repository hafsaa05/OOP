#include <iostream>
#include <vector>
using namespace std;

class SecurityTool {
protected:
    string securityLevel;
    double cost;
    int NumOfDevices;
public:
    SecurityTool(string security, double cost, int devices) {
        if (security != "High" && security != "Medium" && security != "Low") {
            cout << "Invalid Security Level! Select High, Medium, or Low!" << endl;
        } else {
            this->securityLevel = security;
        }

        if (cost <= 0) {
            cout << "Invalid Cost!" << endl;
        } else {
            this->cost = cost;
        }

        this->NumOfDevices = devices;
    }

    void performScan() {
        cout << "Performing a generic security scan!" << endl;
    }
};

class FirewallTool : public SecurityTool {
private:
    vector<int> Ports;
    vector<string> Protocols;
public:
    FirewallTool(string security, double cost, int devices, vector<int> ports, vector<string> protocols)
        : SecurityTool(security, cost, devices), Ports(ports), Protocols(protocols) {
        Protocols = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
    }

    void generateList() {
        int startPort = 6;  // Starting port number chosen from the student ID
        cout << "Allowed ports: " << endl;
        for (int i = startPort+1; i < startPort + 24; ++i) {
            cout << i << "\t";
        }   //printing next 23 numbers i.e from 7 to 29
        cout << endl;
    }

    void performScan() {
        cout << "Performing firewall scan!" << endl;
        if (securityLevel == "High") {
            cout << "Only traffic from allowed ports and protocols are allowed." << endl;
        } else if (securityLevel == "Medium") {
            cout << "All traffic from allowed ports and protocols are allowed, along with the next two ports in sequence." << endl;
            cout << "Next two ports: " << Ports[22] + 1 << " " << Ports[22] + 2 << endl;
        } else { // Low
            cout << "All traffic from allowed ports and protocols are allowed, along with the next 5 ports in sequence and from TCP and DNS protocols." << endl;
            cout << "Next five ports: ";
            for (int i = 0; i < 5; ++i) {
                cout << Ports[22] + i + 1 << " ";
            }
            cout << endl;
            cout << "Additional protocols: TCP, DNS" << endl;
        }
    }
};

int main() {
    cout << "Name: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl;
    FirewallTool obj("High", 2323, 9, {}, {});
    obj.generateList();
    obj.performScan();
    return 0;
}
