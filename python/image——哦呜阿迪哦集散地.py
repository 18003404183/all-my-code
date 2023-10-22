import torch
from torch.utils.data import DataLoader
from torchvision import transforms
from torchvision.datasets import MNIST
import matplotlib.pyplot as plt

class Net(torch.nn.Module):

                    def __init__(self) :
                            super().__init__()
                             