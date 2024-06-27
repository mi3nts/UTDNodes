
from getmac import get_mac_address
import serial.tools.list_ports
import yaml



def findPort(find):
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        currentPort = str(p)
        if(currentPort.endswith(find)):
            return(currentPort.split(" ")[0])


def findDuePort():
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        currentPort = str(p[2])
        if(currentPort.find("PID=2341")>=0):
            return(p[0])

def findNanoPorts():
    ports = list(serial.tools.list_ports.comports())
    outPorts = []
    for p in ports:
        currentPort = str(p)
        if(currentPort.endswith("FT232R USB UART")):
            outPorts.append(currentPort.split(" ")[0])

    return outPorts


def findMacAddress():
    macAddress= get_mac_address(interface="eth0")
    if (macAddress!= None):
        return macAddress.replace(":","")

    macAddress= get_mac_address(interface="docker0")
    if (macAddress!= None):
        return macAddress.replace(":","")

    macAddress= get_mac_address(interface="enp1s0")
    if (macAddress!= None):
        return macAddress.replace(":","")

    return "xxxxxxxx"

def findIPSPorts():
    ports = list(serial.tools.list_ports.comports())
    ipsPorts = []
    for p in ports:
        currentPort = str(p[2])
        if(currentPort.find("PID=10C4")>=0):
            ipsPorts.append(str(p[0]).split(" ")[0])
    return ipsPorts

dataFolderReference       = "/home/teamlary/mintsData/reference"
dataFolderMQTTReference   = "/home/teamlary/mintsData/referenceMQTT"
dataFolder                = "/home/teamlary/mintsData/raw"
dataFolderMQTT            = "/home/teamlary/mintsData/rawMQTT"

ipsPorts                  = findIPSPorts()
nanoPorts                 = findNanoPorts()
macAddress                = findMacAddress()
latestOn                  = False
mqttOn                    = True
gpsPort                   = findPort("GPS/GNSS Receiver")

# For MQTT 
mqttCredentialsFile      = 'mintsXU4/credentials.yml'
mqttBroker               = "mqtt.circ.utdallas.edu"
mqttPort                 =  8883  # Secure port



# For Humidity Corrections
correctionsFile          = 'mintsXU4/corrections.yml'
corrections              = yaml.load(open(correctionsFile))

pmSensor                 = corrections['pmSensor']    
climateSensor            = corrections['climateSensor']    
modelFile                = 'mintsXU4/climateCorrectionModel.joblib'
dataFolderTmp            = "/home/teamlary/mintsDataTmp"

if __name__ == "__main__":

    print("---- MINTS Definitions ----")
    print("Mac Address                : {0}".format(macAddress))
    print("Data Folder Raw            : {0}".format(dataFolder))
    print("Data Folder Raw MQTT       : {0}".format(dataFolderMQTT))
    print("Data Folder Reference      : {0}".format(dataFolderReference))
    print("Data Folder Reference MQTT : {0}".format(dataFolderMQTTReference))
    print("GPS Port                   : {0}".format(gpsPort))
    print("Latest On                  : {0}".format(latestOn))
    print("MQTT On                    : {0}".format(mqttOn))
    print("MQTT Credentials File      : {0}".format(mqttCredentialsFile))
    print("MQTT Broker and Port       : {0}, {1}".format(mqttOn,mqttPort))

    #-------------------------------------------#
    # Corrections 
    print("--- Corrections ---")
    print("PM Sensor                 : {0}".format(pmSensor))
    print("Climate Sensor            : {0}".format(climateSensor))

    #-------------------------------------------#
    print("IPS Ports :")
    for dev in ipsPorts:
        print("\t{0}".format(dev))
        
    #-------------------------------------------#
    print("Nano Ports :")
    for dev in nanoPorts:
        print("\t{0}".format(dev))