using UnityEngine;
using System.IO.Ports;
using TMPro;

enum TaskState
{
    INIT,
    WAIT_PRESS
}

public class Serial : MonoBehaviour
{
    private static TaskState taskState = TaskState.INIT;
    private SerialPort _serialPort;
    private byte[] buffer;
    public TextMeshProUGUI TextRead;
    private string input;
    private string input2;
    private double mensaje;

    void Start()
    {
        _serialPort = new SerialPort();
        _serialPort.PortName = "/dev/ttyUSB0";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.NewLine = "\n";
        _serialPort.Open();
        Debug.Log("Open Serial Port");
        buffer = new byte[128];
    }
    void Update()
    {
        switch (taskState)
        {
            case TaskState.INIT:
                taskState = TaskState.WAIT_PRESS;
                Debug.Log("WAIT COMMANDS");
                break;
            case TaskState.WAIT_PRESS:
          
                if (_serialPort.BytesToRead > 0)
                {
                    string response = _serialPort.ReadLine();
                    Debug.Log(response);
                    TextRead.text = response.ToString();
                }

                break;
            default:
                Debug.Log("State Error");
                break;
        }
    }
    public void ReadLed(string led)
    {
        input = led;
    }
    public void ReadState(string state)
    {
        input2 = state;
    }
    public void pressLedControl()
    {
        if (input == "1")
        {
            mensaje = 1;
        }
        if (input == "2")
        {
            mensaje = 2;
        }
        if (input == "3")
        {
            mensaje = 3;
        }
        if (input2 == "ON")
        {
            mensaje = mensaje + 0.5; 
          
            Debug.Log("Send ON");
        }
        if (input2 == "OFF")
        {
            Debug.Log("Send OFF");
        }

        if (mensaje == 1)
        {
            _serialPort.Write("Led_1_OFF\n");
            Debug.Log("Led_1_OFF");
            mensaje = 0;
        }
        if (mensaje == 1.5)
        {
            _serialPort.Write("Led_1_ON\n");
            Debug.Log("Led_1_ON");
            mensaje = 0;
        }
        if (mensaje == 2)
        {
            _serialPort.Write("Led_2_OFF\n");
            mensaje = 0;
        }
        if (mensaje == 2.5)
        {
            _serialPort.Write("Led_2_ON\n");
            mensaje = 0;
        }
        if (mensaje == 3)
        {
            _serialPort.Write("Led_3_OFF\n");
            mensaje = 0;
        }
        if (mensaje == 3.5)
        {
            _serialPort.Write("Led_3_ON\n");
            mensaje = 0;
        }
    }
    public void pressRead()
    {
        _serialPort.Write("readBUTTONS\n");
        Debug.Log("Send readBUTTONS");
    }
}
