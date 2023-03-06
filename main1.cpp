
#include <iostream>
#include <typeinfo>


template<typename T,typename TState,typename TEvent>
class Test
{
private:
    TState state;
    TEvent event;
public:
    Test(){}
    ~Test(){}
    std::string GetName(T *object){return (typeid(object).name());}
    //std::string GetName(T *object){return __PRETTY_FUNCTION__;}
};
class TestTemplate
{
public:
    TestTemplate(){Test<int,std::string,std::string> *test = new Test<int,std::string,std::string>;}
};

/////////////////////////////////////////
class EventSTA
{
public:
    enum class EventType : char
    {
        Init,
        Option,
        Update,
        Destroy
    };
protected:
    EventType type;
    std::string name;
protected:
    EventSTA(std::string name,EventType type):name(name),type(type){}
public:
    virtual ~EventSTA(){}
public:
    inline std::string GetName()const{return name;}
    inline EventType GetType()const{return type;}
    virtual std::string GetEvent()const=0;
};

class EventInit : public EventSTA
{
public:
    EventInit():EventSTA("init",EventType::Init){}
    //~EventInit(){}
public:
    std::string GetEvent() const override
    {
        std::string format = "name: " + name;
    }
};

class EventOption : public EventSTA
{
public:
    EventOption():EventSTA("option",EventType::Option){}
    //~EventOption(){}
public:
    std::string GetEvent() const override
    {
        std::string format = "name: " + name;
    }
};

class ModelSTA 
{
public:
    ModelSTA(){}
    ~ModelSTA(){}
public:
    static void EventCallback(EventSTA *event)
    {

    }

};


int main()
{
    ModelSTA *mSTA = new ModelSTA;

    getchar();
    return 0;
}
