using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class ArdiunoControl : MonoBehaviour
{
    //the number of com on your computer
    [SerializeField] private int _comIndex = 3;

    private string _comName = "COM";

    //the input port
    private SerialPort _sp;



	// Use this for initialization
	void Start ()
	{
	    _sp = new SerialPort(_comName + _comIndex, 9600);
    }
	
	// Update is called once per frame
	void Update () {
		
	}

    /// <summary>
    /// set the the index of the motor should be moving, and the state of it 
    /// implement this method in a button component to set a specific motor state
    /// </summary>
    /// <param name="index"></param>
    public void SetMotorState(string index)
    {
        _sp.Open();
        _sp.Write(index);
        _sp.Close();
    }

}
