// DownCounter.java
class DownCounter extends AbstractCounter{
	
	//constructor
	DownCounter(int limit){
		this.value = limit;
		this.limit = limit;
	}
	
	void click(){
		value--;
		if(value<1) value = limit;
	
	}
	
	//override inherited function
	void reset(){
		value = limit;
	}
}
