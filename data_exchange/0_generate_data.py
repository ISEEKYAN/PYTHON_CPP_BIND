import json
import numpy as np

x = np.linspace(0, 1e-120, 100000).astype(np.float)
test = {
    "pi": 3.141,
    "happy": True,
    "name": "Niels",
    "nothing": None,
    "answer": {"everything": 42},
    "list": [1, 0, 2],
    "object": {"currency": "USD", "value": 42.99},
    "float_list": list(x),
}

txt = json.dumps(test)
with open("test.json", "w") as f:
    f.write(txt)

import bson

txt = bson.dumps(test)
with open("test.bson", "wb") as f:
    f.write(txt)

import msgpack

txt = msgpack.dumps(test)
with open("test.msgpack", "wb") as f:
    f.write(txt)
