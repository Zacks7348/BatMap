package com.example.batmap;

import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.lang.*;
import java.util.Set;



public class MainActivity extends AppCompatActivity {

BluetoothAdapter adapter;
BluetoothAdapter btAdapter;
BluetoothSocket socket;
BluetoothDevice BLdevice;

Button mainButton;

boolean deviceFound = false;
String DEVICE_NAME = "";



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mainButton = findViewById(R.id.onOFF);

        findDevice();

        mainButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){

            }

        });
    }


    public void findDevice() {
        Set<BluetoothDevice> pairedDevices = adapter.getBondedDevices();
        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                if (device.getName().equals(DEVICE_NAME)) {
                   BLdevice = device;



                    deviceFound = true;
                    break;
                }
            }
        }
    }

}
