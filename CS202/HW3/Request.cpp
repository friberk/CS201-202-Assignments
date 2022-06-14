/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: Request class implementation file for CS202's HW3 assignment.
 */

#include "Request.h"

Request::Request() {
    this->id = 0;
    this->priority = 0;
    this->requestTime = 0;
    this->processTime = 0;
    this->isQueued = false;
}

Request::Request(RequestItemType id, RequestItemType priority, RequestItemType requestTime,
                 RequestItemType processTime, bool isQueued) {
    this->id = id;
    this->priority = priority;
    this->requestTime = requestTime;
    this->processTime = processTime;
    this->isQueued = isQueued;
}

Request::Request(const Request& otherRequest)
    : id(otherRequest.id), priority(otherRequest.priority), requestTime(otherRequest.requestTime),
      processTime(otherRequest.processTime), isQueued(otherRequest.isQueued) {}

Request& Request::operator=(const Request& otherRequest) {
    if (this != &otherRequest) {
        this->id = otherRequest.id;
        this->priority = otherRequest.priority;
        this->requestTime = otherRequest.requestTime;
        this->processTime = otherRequest.processTime;
        this->isQueued = otherRequest.isQueued;
    }

    return *this;
}

Request::~Request() {
    this->id = 0;
    this->priority = 0;
    this->requestTime = 0;
    this->processTime = 0;
    this->isQueued = false;
}

void Request::setId(const RequestItemType& id) { this->id = id; }

void Request::setPriority(const RequestItemType& priority) { this->priority = priority; }

void Request::setRequestTime(const RequestItemType& requestTime) {
    this->requestTime = requestTime;
}

void Request::setProcessTime(const RequestItemType& processTime) {
    this->processTime = processTime;
}

void Request::setIsQueued(const bool& isQueued) {
    this->isQueued = isQueued;
}

RequestItemType Request::getId() const { return this->id; }

RequestItemType Request::getPriority() const { return this->priority; }

RequestItemType Request::getRequestTime() const { return this->requestTime; }

RequestItemType Request::getProcessTime() const { return this->processTime; }

bool Request::getIsQueued() const { return this->isQueued; }

bool operator>(const Request& r1, const Request& r2) {
    return (r1.getPriority() > r2.getPriority()) ||
           (r1.getPriority() == r2.getPriority() && r1.getRequestTime() < r2.getRequestTime());
}
