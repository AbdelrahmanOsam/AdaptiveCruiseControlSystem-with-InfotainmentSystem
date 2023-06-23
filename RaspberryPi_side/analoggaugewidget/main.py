import os
import time
import serial
import sys

from PyQt5 import QtCore, QtGui,QtWidgets
from PyQt5.QtWidgets import QMainWindow, QWidget, QApplication,QLabel
from PyQt5.QtCore import QTimer,QObject

ser = serial.Serial ("/dev/ttyAMA0", 9600) 

#######################################################

################################################################################################
# Convert UI to PyQt5 py file
################################################################################################
#os.system("pyuic5 -o analoggaugewidget_demo_ui.py analoggaugewidget_demo.ui")
# os.system("pyuic5 -o analoggaugewidget_demo_ui.py analoggaugewidget_demo.ui.oQCkCR")

################################################################################################
# Import the generated UI
################################################################################################
from analoggaugewidget_demo_ui import *

################################################################################################
# MAIN WINDOW CLASS
################################################################################################
class MainWindow(QMainWindow):
    
    speed = 0

    def __init__(self, parent=None):
        QMainWindow.__init__(self)
        super().__init__(parent)
        self.timer = QTimer(self)
        ################################################################################################
        # Setup the UI main window
        ################################################################################################
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        #### access ButtonDistance my edit #########
        self.ui.ButtonDistance50.clicked.connect(self.ButtonDistance50Func)
        self.ui.ButtonDistance75.clicked.connect(self.ButtonDistance75Func)
        self.ui.ButtonDistance100.clicked.connect(self.ButtonDistance100Func)
        #### access ButtonDistance my edit #########
        self.ui.ButtonACC_ON.clicked.connect(self.ButtonACC_ONFunc)
        self.ui.ButtonNCC_ON.clicked.connect(self.ButtonNCC_ONFunc)
        self.ui.ButtonCC_OFF.clicked.connect(self.ButtonCC_OFFFunc)
       
        ######################################
        ################################################################################################
        # Show window
        ################################################################################################
        self.show()
        ############ function for ButtonDistance My edit ######################
    def ButtonDistance50Func(self):
            #print 50 in text box of gui
        #print 50 in text box of gui
        self.ui.TextODistanceMode.setText("50 CM ")
            #write distance in external file
        ser.write(b"0")

        
    def ButtonDistance75Func(self):
        self.ui.TextODistanceMode.setText("75 CM ")
          #write distance in external file
        
        ser.write(b"1")
    def ButtonDistance100Func(self):
        self.ui.TextODistanceMode.setText("100 CM ")
          #write distance in external file
        ser.write(b"2")

        ############ function for ButtonCC My edit ######################
    def ButtonACC_ONFunc(self):
        self.ui.TextCC_O_Mode.setText("ACC")
        self.ui.TextOCC_Statue.setText("CC ON ")
          #write distance in external file
        ser.write(b"3")

    def ButtonNCC_ONFunc(self):
        self.ui.TextCC_O_Mode.setText("NCC")
        self.ui.TextOCC_Statue.setText("CC ON ")

          #write distance in external file
        ser.write(b"4")

    def ButtonCC_OFFFunc(self):
        self.ui.TextCC_O_Mode.setText("NONE")
        self.ui.TextOCC_Statue.setText("CC OFF ")

          #write distance in external file
        ser.write(b"5")

        ###########################################
    def update(self):
        if ser.inWaiting():
             MainWindow.speed = int(ser.read(2))
        print( MainWindow.speed)
        self.ui.SpeedLCD.display( MainWindow.speed)
        self.ui.widget.updateValue( MainWindow.speed) 

########################################################################
## EXECUTE APP
########################################################################
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ########################################################################
    ## 
    ########################################################################
    window = MainWindow()
    
    MainWindow.timer = QTimer(window)
    MainWindow.timer.timeout.connect(window.update)
    MainWindow.timer.start(5)
    window.show()
    sys.exit(app.exec_())

########################################################################
## END===>
########################################################################  
