//
// Created by Kevin Zheng on 11/9/2025.
//

#include <iostream>
#include <iomanip>
#include "simulation/Simulation.h"
#include "objects/ClothObject.h"
#include "objects/RopeObject.h"
#include "utils/Constants.h"

int main() {
    std::cout << "2D Mass-Spring Simulation" << std::endl;
    std::cout << "=========================" << std::endl;

    Simulation sim;

    ClothObject cloth(0.0f, 0.0f, 8, 8, 0.2f);
    RopeObject rope(3.0f, 0.0f, 10, 0.15f);

    for (PointMass* pm : cloth.getPointMasses()) {
        sim.addPointMass(pm);
    }
    for (Spring* spring : cloth.getSprings()) {
        sim.addSpring(spring);
    }
    for (PointMass* pm : rope.getPointMasses()) {
        sim.addPointMass(pm);
    }
    for (Spring* spring : rope.getSprings()) {
        sim.addSpring(spring);
    }

    Vector2D gravity(0, Constants::GRAVITY);

    float dt = Constants::FIXED_TIME_STEP;
    int steps = 300;

    std::cout << std::fixed << std::setprecision(3);

    for (int i = 0; i < steps; i++) {
        sim.applyGlobalForce(gravity);
        sim.update(dt);

        if (i % 30 == 0) {
            std::cout << "Step " << i << ":" << std::endl;
            const auto& pointMasses = sim.getPointMasses();
            for (int j = 0; j < std::min(3, (int) pointMasses.size()); j++) {
                Vector2D pos = pointMasses[j]->getPosition();
                std::cout << " PM " << j << ": (" << pos.x << ", " << pos.y << ")" << std::endl;
            }
            std::cout << std::endl;
        }
    }

    std::cout << "Simulation completed!" << std::endl;
    std::cout << "Total point masses: " << sim.getPointMasses().size() << std::endl;
    std::cout << "Total springs: " << sim.getSprings().size() << std::endl;

    return 0;
}