package monitor_example;

public class Main {
	
	/**
	* Function: Main Function of the program
	* @param {String[]} - Args
	* @return {void}
	* 
	* @precondition: none
	* @postcondition: none
	*/
	public static void main(String[] args) {
		
		Counter contador = new Counter();
		
		ThreadObject p1 = new ThreadObject(contador, "P1");
		ThreadObject p2 = new ThreadObject(contador, "P2");		
			
		p1.start();	
		p2.start();	
		
		try {
			p1.join();
			p2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		System.out.println(contador.getCount());
	}
}
