class Human{
	public:
	int GetHeight() const {return m_height;}
	int GetWeight() const {return m_weight;}
	void SetHeight(int height) {m_height=height;}
	void SetWeight(int weight) {m_weight=weight;}
	void School(void) const {std::cout<<"Its just School\n";}
	Human(int height,int weight);
	~Human();

	
	private:
	int m_height;
	int m_weight;
	
};