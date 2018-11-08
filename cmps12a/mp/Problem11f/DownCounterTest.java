class DownCounterTest{
	public static void main( String[] args ){
		DownCounter a = new DownCounter(5);
		DownCounter b = new DownCounter(7);
		for(int i=0; i<11; i++){
			System.out.println(a+" "+b);
			a.click();
			b.click();
		}
		System.out.println(a+" "+b);
		clickAndShow(a);
		resetAndShow(a);
	}
	// clickAndShow()
	// calls click() then prints c
	static void clickAndShow( AbstractCounter c ){
		c.click();
		System.out.println(c);
	}

	// resetAndShow()
	// calls reset() then prints c
	static void resetAndShow( AbstractCounter c ){
		c.reset();
		System.out.println(c);
	}
}
