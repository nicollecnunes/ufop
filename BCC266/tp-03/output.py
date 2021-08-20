from rich.console import Console
from rich.table import Table
from rich import box
from rich.align import Align
from rich.layout import Layout
from rich.panel import Panel

class Output:
    @staticmethod
    def printResult(cacheHit1, cacheMiss1, cacheHit2, cacheMiss2, cacheHit3, cacheMiss3, ramHit, custoTotal):        
        
        cacheTaxa1 = ((cacheHit1 * 100) / (cacheHit1 + cacheMiss1)) if cacheHit1 > 0 or cacheMiss1 > 0 else 0
        cacheTaxa2 = ((cacheHit2 * 100) / (cacheHit2 + cacheMiss2)) if cacheHit2 > 0 or cacheMiss2 > 0 else 0
        cacheTaxa3 = ((cacheHit3 * 100) / (cacheHit3 + cacheMiss3)) if cacheHit3 > 0 or cacheMiss3 > 0 else 0
        
        layout = Table.grid()

        #tabela hit/miss
        hit_table_cache = Table(box=box.SIMPLE_HEAD)

        hit_table_cache.add_column("")
        hit_table_cache.add_column("Hit")
        hit_table_cache.add_column("Miss")
        hit_table_cache.add_row("Cache 1",str(cacheHit1), str(cacheMiss1))
        hit_table_cache.add_row("Cache 2",str(cacheHit2), str(cacheMiss2))
        hit_table_cache.add_row("Cache 3",str(cacheHit3), str(cacheMiss3))
        hit_table_cache.add_row("RAM",str(ramHit),"-")
        hit_table_cache.add_row("Total",str(cacheHit1+cacheHit2+cacheHit3+ramHit),str(cacheMiss1+cacheMiss2+cacheMiss3))

        #taxa de uso
        taxa_table_cache = Table(box=box.SIMPLE_HEAD)
        taxa_table_cache.add_column("Cache 1")
        taxa_table_cache.add_column("Cache 2")
        taxa_table_cache.add_column("Cache 3")
        taxa_table_cache.add_row(str(round(cacheTaxa1,2))+"%",str(round(cacheTaxa2,2))+"%",str(round(cacheTaxa3,2))+"%")

        layout.add_row(Panel.fit(
                hit_table_cache, title="Hit/Miss", border_style="green"
        ))

        layout.add_row(Panel.fit(
                taxa_table_cache, title="Taxa", border_style="green"
        ))

        layout.add_row(Panel.fit(str(custoTotal), title="Custo", border_style="green"))

        #return layout
        console = Console()
        console.print(layout)