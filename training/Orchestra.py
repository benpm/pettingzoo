import ray
import numpy as np
from training.Section import Section
import pandas as pd
ray.init(local_mode=True)

class Orchestra:
    def __init__(self, nSections, nAgents, AgentClass, ss) -> None:
        print("Initializing Orchestra")

        self.gen = np.random.default_rng(ss.spawn(1)[0])

        self.nSections = nSections
        self.nAgents   = nAgents

        self.sizes = []
        self.genRanges()

        self.sections = [
            Section.remote(ID, n, AgentClass, ss.spawn(1)[0]) for ID, n in enumerate(self.sizes)
        ]

    def genRanges(self):
        # Borrowed from the numpy v1.19.0 source of `array_split` :)
        Neach_section, extras = divmod(self.nAgents, self.nSections)
        self.sizes = extras * [Neach_section+1] + (self.nSections-extras) * [Neach_section]

    def play(self, gameArgs):
        print("Playing Orchestra")

        futures = []
        for sec in self.sections:
            futures.append(sec.play.remote(gameArgs))

        results = ray.get(futures)
        results = [r for sec in results for r in sec] # Flatten
        df = pd.DataFrame(results, columns=('Fitness', 'Death Type'))        

        return df