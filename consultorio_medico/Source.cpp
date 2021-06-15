

#include "fecha.h"
#include <map>
#include <unordered_map>
using namespace std;


class Consultorio {
public:

	void nuevoMedico(const string& medico) {
		medicos.insert(medico, {});
	}

	void pideConsulta(const string& paciente, const string& medico, const Fecha &fecha) {
		if (!medicos.count(medico)) {//el medico no esta dado de alta
			throw domain_error("Medico no existente");
		}
		else {
			//busco las citas de ese medico
			auto med = medicos.find(medico);
			auto citas = med->second;
			if (citas.count(fecha)) { //fecha ocupada
				throw domain_error("Fecha ocupada");
			}
			else {//anyado la cita
				citas.insert({ fecha, paciente });
			}
		}
	}

	string siguientePaciente(const string& medico) {
		if (!medicos.count(medico)) {//el medico no esta dado de alta
			throw domain_error("Medico no existente");
		}
		else {
			auto med = medicos.find(medico);
			auto pacientes = med->second;
			if (pacientes.empty()) {//no tiene pacientes asignados
				throw domain_error("El medico no tiene pacientes asignados");
			}
			else {
				//devolvemos el nombre del paciente que le toca
				return pacientes.begin()->second;
			}
		}
	}

	void atiendeConsulta(const string& medico) {
		if (!medicos.count(medico)) {//el medico no esta dado de alta
			throw domain_error("Medico no existente");
		}
		else {
			auto med = medicos.find(medico);
			auto pacientes = med->second;
			if (pacientes.empty()) {//no tiene pacientes asignados
				throw domain_error("El medico no tiene pacientes asignados");
			}
			else {
				//eliminamos al siguiente paciente del medico
				//es decir, el primero
				auto it = pacientes.begin();
				pacientes.erase(it);
			}
		}
	}

	vector<pair<Fecha,string>> listaPacientes(const string& medico, const int& dia) {
		vector<pair<Fecha, string>> resul;
		if (!medicos.count(medico)) {//el medico no esta dado de alta
			throw domain_error("Medico no existente");
		}
		else {//voy sacando los pacientes al vector,por fecha
			auto medi = medicos.find(medico);
			auto pacientesMed = medi->second;

			auto iter = pacientesMed.lower_bound({dia,0,0});
			while (iter != pacientesMed.end() && iter->first.get_dia() == dia) {
				resul.push_back({ iter->first, iter->second });
				iter++;
			}

		}
		return resul;
	}



private:
	using citasMedico = map<Fecha, string>;
	unordered_map<string, citasMedico> medicos;

	citasMedico& buscar_citas(const string& nombre) {
		auto it = medicos.find(nombre);
		if (it == medicos.end()) {
			throw domain_error("NO EXISTE EL MEDICO");
		}
		else {
			return it->second; //devuelve la cita
		}
	}

	const citasMedico& buscar_citas(const string& nombre) const{
		auto it = medicos.find(nombre);
		if (it == medicos.end()) {
			throw domain_error("NO EXISTE EL MEDICO");
		}
		else {
			return it->second; //devuelve la cita
		}
	}
};