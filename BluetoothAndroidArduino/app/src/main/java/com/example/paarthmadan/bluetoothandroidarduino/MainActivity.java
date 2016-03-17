package com.example.paarthmadan.bluetoothandroidarduino;

import android.os.Bundle;
import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;
import android.content.ActivityNotFoundException;
import android.speech.RecognizerIntent;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.Locale;

import static android.content.pm.ActivityInfo.*;

public class MainActivity extends Activity {


    BluetoothAdapter mBluetoothAdapter;
    BluetoothSocket mmSocket;
    BluetoothDevice mmDevice;
    OutputStream mmOutputStream;
    InputStream mmInputStream;
    volatile boolean stopWorker;



    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setRequestedOrientation(SCREEN_ORIENTATION_PORTRAIT);

        Button openButton = (Button) findViewById(R.id.connect);
        Button closeButton = (Button) findViewById(R.id.disconnect);
        Button sendButton = (Button) findViewById(R.id.send);


        // Open Button
        openButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                try {
                    findBT();
                    openBT();
                } catch (IOException ex) {
                }
            }
        });

        // Close button
        closeButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                try {
                    closeBT();
                } catch (IOException ex) {
                }
            }
        });

        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    sendString();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        });
    }

    void findBT() {
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        if (mBluetoothAdapter == null) {

        }

        if (!mBluetoothAdapter.isEnabled()) {
            Intent enableBluetooth = new Intent(
                    BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBluetooth, 0);
        }

        Set<BluetoothDevice> pairedDevices = mBluetoothAdapter
                .getBondedDevices();

        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                if (device.getName().equals("HC-07")) // this name have to be
                // replaced with your
                // bluetooth device name
                {
                    mmDevice = device;
                    Log.v("ArduinoBT",
                            "findBT found device named " + mmDevice.getName());
                    Log.v("ArduinoBT",
                            "device address is " + mmDevice.getAddress());
                    break;
                }
            }
        }

    }

    void openBT() throws IOException {

        UUID uuid = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb"); // Standard
        // SerialPortService
        // ID
        mmSocket = mmDevice.createRfcommSocketToServiceRecord(uuid);
        mmSocket.connect();
        mmOutputStream = mmSocket.getOutputStream();
        mmInputStream = mmSocket.getInputStream();


    }


    void sendString() throws IOException {
        Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        i.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
        i.putExtra(RecognizerIntent.EXTRA_LANGUAGE, Locale.getDefault());
        i.putExtra(RecognizerIntent.EXTRA_PROMPT, "Say Something!");

        try {
                System.out.println("success 1");
                startActivityForResult(i, 100);
            }
        catch (ActivityNotFoundException a)
            {
                Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_LONG).show();
            }





    }

    public void onActivityResult(int requestcode, int resultcode, Intent i){


        super.onActivityResult(requestcode, resultcode, i);

        System.out.println("success 3 \t" + resultcode);

        switch(requestcode){
            case 100:

                if(resultcode == RESULT_OK && i != null){
                    System.out.println("success");
                    ArrayList<String> results = i.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);

                    try{
                        mmOutputStream.write(results.get(0).getBytes());
                    }
                    catch (Exception e){
                        Toast.makeText(MainActivity.this, "Could not send message!", Toast.LENGTH_SHORT).show();
                    }


                }

                break;
        }

    }

    void closeBT() throws IOException {
        stopWorker = true;
        mmOutputStream.close();
        mmInputStream.close();
        mmSocket.close();

    }

}