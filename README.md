# ESP32 AWS IoT Weather Station 🌦️

An ESP32-based IoT weather station that collects real-time temperature and humidity data and publishes it to AWS IoT Core over MQTT. Data is processed via AWS Lambda and stored in DynamoDB for serverless, scalable monitoring.

## Features

ESP32 device for sensor data collection (C++).

MQTT-based communication with AWS IoT Core.

AWS Lambda + DynamoDB backend for real-time data storage.

## Getting Started

Flash ESP32 with provided firmware (Arduino IDE / PlatformIO).

Configure Wi-Fi and AWS IoT Core credentials.

Deploy Lambda + DynamoDB backend using provided scripts.

Visualize real-time sensor data on the AWS console or dashboards.
