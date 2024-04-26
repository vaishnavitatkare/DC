import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;

public class SampleServerImpl extends UnicastRemoteObject implements SampleServer {
    SampleServerImpl() throws RemoteException {
        super();
    }

    public int sum(int a, int b) throws RemoteException {
        return (a + b);
    }

    public static void main(String args[]) {
        try {
            System.setSecurityManager(new RMISecurityManager()); // Set the security manager

            // Create a local instance of the object
            SampleServerImpl server = new SampleServerImpl();

            // Put the local instance in the registry
            Naming.rebind("SAMPLE-SERVER", server);

            System.out.println("Server waiting...");
        } catch (java.net.MalformedURLException me) {
            System.out.println("Malformed URL: " + me.toString());
        } catch (RemoteException re) {
            System.out.println("Remote exception: " + re.toString());
        }
    }
}
