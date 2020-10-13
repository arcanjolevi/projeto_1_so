package packageMonitorExample;

public class ThreadObject implements Runnable {
	private Thread t;
	private String threadName;
	private Counter counterRef;
	
	
	/**
	* Function: Constructor of the ThreadObject class
	* @param {Counter} - Reference to a counter
	* @param {String} - Thread name
	* @returns {Process} counter value
	* 
	* @precondition: none
	* @postcondition: none
	*/
	ThreadObject(Counter _counterRef, String _threadName){
		counterRef = _counterRef;
		threadName = _threadName;
	}
	
	/**
	* Function: Run method - Actions that will be run when thread starts
	* @returns {void} 
	* 
	* @precondition: none
	* @postcondition: none
	*/
	public void run() {
		for(int i = 0; i < 1000;i++) {
			counterRef.increment();
		}
		
		//System.out.println(counterRef.getCount());
	}
	
	
	/**
	* Function: Method that will be start the thread
	* @returns {void} 
	* 
	* @precondition: none
	* @postcondition: thread started
	*/
	public void start () {
		System.out.println("Starting " +  threadName );
	    if (t == null) {
	    	t = new Thread (this, threadName);
	        t.start ();
	    }
	}
	
	
	public void join() throws InterruptedException {
		t.join();
	}
}
