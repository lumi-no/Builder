#include <iostream>
#include <string>
#include <memory>


class House {
private:
    std::string walls;
    std::string roof;
    std::string foundation;

public:
    void setWalls(const std::string& walls) {
        this->walls = walls;
    }

    void setRoof(const std::string& roof) {
        this->roof = roof;
    }

    void setFoundation(const std::string& foundation) {
        this->foundation = foundation;
    }

    void show() const {
        std::cout << "House with " << foundation << ", " << walls << " walls, and " << roof << " roof." << std::endl;
    }
};


class HouseBuilder {
public:
    virtual void buildFoundation() = 0;
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual std::shared_ptr<House> getResult() = 0;
    virtual ~HouseBuilder() = default;
};


class WoodenHouseBuilder : public HouseBuilder {
private:
    std::shared_ptr<House> house;

public:
    WoodenHouseBuilder() {
        house = std::make_shared<House>();
    }

    void buildFoundation() override {
        house->setFoundation("wooden foundation");
    }

    void buildWalls() override {
        house->setWalls("wooden");
    }

    void buildRoof() override {
        house->setRoof("wooden roof");
    }

    std::shared_ptr<House> getResult() override {
        return house;
    }
};


class StoneHouseBuilder : public HouseBuilder {
private:
    std::shared_ptr<House> house;

public:
    StoneHouseBuilder() {
        house = std::make_shared<House>();
    }

    void buildFoundation() override {
        house->setFoundation("stone foundation");
    }

    void buildWalls() override {
        house->setWalls("stone");
    }

    void buildRoof() override {
        house->setRoof("stone roof");
    }

    std::shared_ptr<House> getResult() override {
        return house;
    }
};


class Director {
private:
    std::shared_ptr<HouseBuilder> builder;

public:
    void setBuilder(const std::shared_ptr<HouseBuilder>& builder) {
        this->builder = builder;
    }

    void construct() {
        builder->buildFoundation();
        builder->buildWalls();
        builder->buildRoof();
    }
};

int main() {
    Director director;

    auto woodenBuilder = std::make_shared<WoodenHouseBuilder>();
    director.setBuilder(woodenBuilder);
    director.construct();
    auto woodenHouse = woodenBuilder->getResult();
    woodenHouse->show();

    auto stoneBuilder = std::make_shared<StoneHouseBuilder>();
    director.setBuilder(stoneBuilder);
    director.construct();
    auto stoneHouse = stoneBuilder->getResult();
    stoneHouse->show();

    return 0;
}
