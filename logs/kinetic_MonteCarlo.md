# Logs of Kinetic Monte Carlo

## 2024-11-20 [871220]

I asked Claudes Sonnet for some guidance about our to restructure my project in order to separate the kMC engine to the model and the visualization. With its reponses, I discovered several tricks that seem really powerful and useful:

- use of dataclasses for writing in a proper and readeable way classes composed of constants
- use of abstract class to create an interface so the kMC engine can be fully independant of the models definition as long that is contains 4 functions (`rates()`, `initial_states()`, `apply_reaction()`, and `check_enabled_reaction()`)
- use of decorators like
  - `@property` which basically turn the return of a function as a property that can be accessed without parenthesis
  - `@dataclasses` which removes the need of using `__init__` and `self.` for classes
