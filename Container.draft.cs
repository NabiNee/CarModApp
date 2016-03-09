// draft of data structures to be used in the app
// Note: these are currently not finished 
// Note 2: this must be as the containo for passing information from devices in the system...

public class User{

	private:
		// User information
		int Userid;
		String userName;
		String userPassword;
		boolean userHistory;
		
		// application Object saves 
		Car carModel;
		
		//Gallery gallery;
		
		
		
	public:	
		
		// major methods
		
		// get set methods
		int getUserId();
		String getUserName();
		String getUserPassword();
		bool getHistory();
		Car getCarInfo();
		
		void setUserId(int id){userId = id};
		void setUserName(String name){userName = name};
		void setUserPassword(String password){userPassword = password};
		
		// car model set methods
		
};

public class Cars{
	
	private:
		Part wheel;
		Part engine;
		Part hood;
		Part exhaust;
		Part lights;
		// continue adding here
}

public class Part{
	
	private:
		int partId;
		int partRefNum;
		String partName;
		String partSource;
		
		ArrayList<String> partSellers;
		
		
}