import numpy as np
import pickle
import struct

with open('sample_weight.pkl', 'rb') as f:
    sample_weights = pickle.load(f)

sample_weights['W1'] = np.array(sample_weights['W1'], dtype=np.float32)
sample_weights['W2'] = np.array(sample_weights['W2'], dtype=np.float32)
sample_weights['W3'] = np.array(sample_weights['W3'], dtype=np.float32)
sample_weights['b1'] = np.array(sample_weights['b1'], dtype=np.float32)
sample_weights['b2'] = np.array(sample_weights['b2'], dtype=np.float32)
sample_weights['b3'] = np.array(sample_weights['b3'], dtype=np.float32)

with open('sample_weight.bin', 'wb') as f:
    for weight in ['W1', 'W2', 'W3']:
        f.write(struct.pack('I', sample_weights[weight].shape[0]))
        f.write(struct.pack('I', sample_weights[weight].shape[1]))
        f.write(sample_weights[weight].flatten().tobytes())
    for bias in ['b1', 'b2', 'b3']:
        f.write(struct.pack('I', sample_weights[bias].shape[0]))
        f.write(sample_weights[bias].tobytes())
