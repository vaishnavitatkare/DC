import java.io.*;
import java.net.*;

public class SocketClient {
    public static void main(String[] args) {
        final String serverHost = "localhost";
        final int serverPort = 8080;

        try (Socket s = new Socket(serverHost, serverPort);
             DataOutputStream dout = new DataOutputStream(s.getOutputStream())) {

            System.out.println("Connected to server.");

            dout.writeUTF("Welcome to the new world...");
            dout.flush();

            System.out.println("Message sent to server.");

        } catch (ConnectException ce) {
            System.err.println("Connection refused. Make sure the server is running.");
        } catch (IOException e) {
            System.err.println("Error communicating with the server: " + e.getMessage());
        }
    }
}
