#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// 基本的なコンポーネントインターフェース
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};
// コンポーネントAの具体的な実装
class ConcreteComponentA : public Component {
public:
    void operation() override {
        std::cout << "Operation of ConcreteComponentA\n";
    }
};
// コンポーネントBの具体的な実装
class ConcreteComponentB : public Component {
public:
    void operation() override {
        std::cout << "Operation of ConcreteComponentB\n";
    }
};

template <typename T>
class Singleton{
public:
    static T& getInstance(){
        static T instance;
        return instance;
    }
    //コピー＆ムーブを禁止
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton(){}
    virtual ~Singleton() {}
};

class Registry : public Singleton<Registry>{
    friend class Singleton<Registry>; // Singletonクラスからのみコンストラクタのアクセスを可能にする

private:
    Registry() {}
    ~Registry() = default;
    std::unordered_map<std::string, std::shared_ptr<Component>> registry_;

public:
    void registerComponent(const std::string& id, std::shared_ptr<Component> component){
        registry_[id] = component;
    }

    std::shared_ptr<Component> getComponent(const std::string& id){
        auto it = registry_.find(id);
        if (it != registry_.end()){
            return it->second;
        } else {
            return nullptr;
        }
    }
};

int main(){
    auto& registry = Registry::getInstance();
    registry.registerComponent("A", std::make_shared<ConcreteComponentA>());
    registry.registerComponent("B", std::make_shared<ConcreteComponentB>());

    auto componentA = registry.getComponent("A");
    componentA->operation();

    auto componentB = registry.getComponent("B");
    componentB->operation();

    return 0;
}

/*
class Singleton {
public:
    virtual ~Singleton() {}
    virtual void sayHello() const = 0;
protected:
    Singleton() {}
private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};

class DataRegistry : public Singleton{
public:
    DataRegistry() {}
    ~DataRegistry() = default;

    static DataRegistry& getInstance() {
        static DataRegistry instance;
        return instance;
    }
    
    void sayHello() const override {
        std::cout << "Hello, I'm a database." << std::endl;
    }

private:
    DataRegistry(const DataRegistry&) = delete;
    DataRegistry& operator=(const DataRegistry&) = delete;
};

int main(){
    DataRegistry dataRegistry;
    dataRegistry.sayHello();
    return 0;
}
*/