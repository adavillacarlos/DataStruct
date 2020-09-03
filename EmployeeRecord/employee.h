struct namerec{
	char last[15];
	char first[15];
	char middle[15];
};

struct payrecord{
	int id;
	struct namerec name;
	float hours, rate;
	float regular, overtime;
	float gross, tax_withheld, net;
};

typedef struct payrecord payrecord;

// reads a single name
void readName(payrecord payroll[], int i);

// prints a single name
void printName(payrecord payroll[], int i); 

// prints total tax gross pay and total tax withheld.
void printSummary(double gross, double tax);

// reads payroll input data records until n records have been read.
void readRecords(payrecord payroll[], int n);

// prints n payroll records.
void printRecords(payrecord payroll[], int n);

// computes regular and overtime pay, and the tax to be withheld.
// also cumulatively sums total gross pay and total tax withheld.
// passes the address of tax initialized to 0 and returns the gross.
double calcRecords(payrecord payroll[], int n, double *taxptr);

//helper functions
void gotoxy(int x, int y);
void menu(); 
int createSize();
void Exit();


