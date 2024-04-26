import java.io.*;
import java.net.*;

public class SocketServer {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(8080);
            System.out.println("Server started. Waiting for clients...");

            Socket s = ss.accept(); // Establishes connection
            DataInputStream dis = new DataInputStream(s.getInputStream());
            String message = dis.readUTF();
            System.out.println("Received message: " + message);

            ss.close();
            s.close();
            dis.close();

        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}
