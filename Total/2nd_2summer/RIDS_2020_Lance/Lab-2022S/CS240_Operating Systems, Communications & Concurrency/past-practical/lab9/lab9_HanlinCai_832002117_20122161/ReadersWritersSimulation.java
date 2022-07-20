public class ReadersWritersSimulation {
	public static void main (String args[]) {
		DataAccessPolicyManager accessPolicyManager = new DataAccessPolicyManager();
		Reader reader1 = new Reader(accessPolicyManager);
		Reader reader2 = new Reader(accessPolicyManager);
		Reader reader3 = new Reader(accessPolicyManager);
		Writer writer = new Writer(accessPolicyManager);

		reader1.start();
		reader2.start();
		reader3.start();
		writer.start();
	}
}
