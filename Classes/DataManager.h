#ifndef  _DATA_MANAGER_H_
#define  _DATA_MANAGER_H_

//namespace myGame {

	class  DataManager
	{
	private:
		DataManager();

	public:
		void onInit();

		virtual ~DataManager();

		static DataManager* getInstance();
	};

#define DM DataManager::getInstance()

//}
#endif // _DATA_MANAGER_H_