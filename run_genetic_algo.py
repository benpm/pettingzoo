from genetic_algo import GeneticAlgorithm
from training import evaluate_generation, breed_generation, RunLogger
from training import construct_generator, get_seeds, get_agents, initialize_ray
from models.FFNN import FFNN, breed
from tqdm import trange

def main():
    initialize_ray(local=False)

    run_seed        = 1
    num_agents      = 100
    num_generations = 100

    agent_class   = FFNN
    agent_breeder = breed

    agent_args = {
        'view_r': 11,
        'view_c': 11,
        'hlc': 2,
        'npl': 144,
    }

    game_args = {
        'num_chunks': 10,
        'seed': 1,
    }

    # Set up random number generators for agents / everything else
    master_rng = construct_generator(run_seed)

    # Set up genetic algorithm
    gen_algo_seed = get_seeds(master_rng)
    gen_algo = GeneticAlgorithm(gen_algo_seed)

    # Set up run logger
    logger = RunLogger("./runs/test/")

    # Get agents
    agents = get_agents(FFNN, agent_args, num_agents, master_rng)

    for i in trange(num_generations):
        fitnesses, death_types = evaluate_generation(agents, game_args)
        logger.log_generation(agents, fitnesses, death_types, game_args)

        survivors = gen_algo.select_survivors(fitnesses)
        breeding_pairs = gen_algo.select_breeding_pairs(survivors)

        agents = breed_generation(agents, agent_breeder, breeding_pairs, master_rng)

if __name__ == "__main__":
    main()