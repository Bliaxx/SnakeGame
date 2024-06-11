#pragma once

class IScorable {
public:
    virtual ~IScorable() = default;
    virtual int GetScoreValue() const = 0;
};
