#ifndef FirebaseConfigHelper_h
#define FirebaseConfigHelper_h

#include <string>

class FirebaseConfigHelper
{
private:

    std::string mCurrentPlayerID;
    uint64_t mCacheRefresh;
    uint64_t mCheatCacheRefresh;
private:

    auto* getRemoteConfigInstance();
    FirebaseConfigHelper();
    virtual ~FirebaseConfigHelper();

public:

    static FirebaseConfigHelper* getInstance();
    void init();
};


#endif //FirebaseConfigHelper_h