package com.example;

import jakarta.xml.ws.Service;
import javax.xml.namespace.QName;
import java.net.URI;
import java.net.URL;

public class SoapClient {
    public static void main(String[] args) throws Exception {
        // 1. URL of the published WSDL
        URL wsdlUrl = new URI("http://localhost:8080/ws/hello?WSDL").toURL();

        // 2. QName of the service (Target Namespace, Service Name)
        // These must match the @WebService annotations on HelloWorldImpl exactly!
        QName qname = new QName("https://example.com/ws", "HelloWorldService");

        // 3. Create the service factory
        Service service = Service.create(wsdlUrl, qname);

        // 4. Extract the endpoint interface
        HelloWorld hello = service.getPort(HelloWorld.class);

        // 5. Call the remote method
        System.out.println("Sending request to server...");
        String response = hello.sayHello("Developer");

        System.out.println("Server responded: " + response);
    }
}