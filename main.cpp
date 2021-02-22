/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jauhari
 *
 * Created on February 21, 2021, 11:22 AM
 */

#include "ImageResizer.h"
#include "crow.h"

void ResizerImageRoute(crow::Crow<>& app) {
    app.route_dynamic("/resize_image").methods("POST"_method)(
            [](const crow::request & req) {
                auto bodyx = crow::json::load(req.body);
                crow::json::wvalue responses;
                if (bodyx.error() == 0) {
                    if (bodyx.has("input_jpeg") && bodyx.has("desired_width") && bodyx.has("desired_height")) {
                        ImageResizer imgResizer;
                                std::string basenampat = bodyx["input_jpeg"].s();
                                long width = bodyx["desired_width"].i();
                                long height = bodyx["desired_height"].i();
                        if (imgResizer.ResizeImage(basenampat, width, height)) {
                            responses["code"] = 200;
                                    responses["message"] = "success";
                                    responses["output_jpeg"] = basenampat;
                        } else {
                            responses["code"] = 400;
                                    responses["message"] = basenampat;
                        }
                        return responses;
                    } else responses["message"] = "payload doesn't contain the right variables";
                    } else responses["message"] = "payload isn't json";
                        responses["code"] = 400;
                    return responses;
                }
    );
}

void InitializeRoute(crow::Crow<>& app) {
    ResizerImageRoute(app);
}

int main(int argc, char** argv) {
    crow::SimpleApp app;
    InitializeRoute(app);
    app.port(8080).multithreaded().run();
    return 0;
}