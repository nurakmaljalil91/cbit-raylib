#include "Component.h"

Component::Component(){}
Component::~Component(){}



void Component::Set_Position(Vector3 mPosition){
    position = mPosition;
}

Vector3 Component::Get_Position(){
    return position;
}

